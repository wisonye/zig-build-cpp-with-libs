const std = @import("std");

///
///
///
pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // -----------------------------------------------------------------------
    // `cpp_temp` C++ binary without `main.zig`
    // -----------------------------------------------------------------------
    const cpp_temp = b.addExecutable(.{
        .name = "cpp_temp",
        .root_source_file = null,
        .target = target,
        .optimize = optimize,
    });

    const cflags = [_][]const u8{
        "-pedantic-errors",
        "-Wc++11-extensions",
        "-std=c++17",
        "-g",
    };
    cpp_temp.addCSourceFile("src/main.cpp", &cflags);

    // Extra include path
    cpp_temp.addIncludePath("./src/utils");

    // Link CPP
    cpp_temp.linkLibCpp();

    // Library path
    cpp_temp.addLibraryPath("./build");

    // Link related libs
    cpp_temp.linkSystemLibrary("a");
    cpp_temp.linkSystemLibrary("b");

    b.installArtifact(cpp_temp);

    const run_cmd = b.addRunArtifact(cpp_temp);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run-cpp", "Run C++ binary");
    run_step.dependOn(&run_cmd.step);

    // -----------------------------------------------------------------------
    // `temp` zig binary
    // -----------------------------------------------------------------------
    const zig_temp = b.addExecutable(.{
        .name = "zig_temp",
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });

    b.installArtifact(zig_temp);

    const zig_run_cmd = b.addRunArtifact(zig_temp);
    zig_run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        zig_run_cmd.addArgs(args);
    }

    const zig_run_step = b.step("run-zig", "Run zig binary");
    zig_run_step.dependOn(&zig_run_cmd.step);
}
