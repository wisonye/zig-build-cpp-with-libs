const std = @import("std");

///
///
///
pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // -----------------------------------------------------------------------
    // `cpp_binary` C++ binary without `main.zig`
    // -----------------------------------------------------------------------
    const cpp_binary = b.addExecutable(.{
        .name = "cpp_binary",
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
    cpp_binary.addCSourceFile("src/main.cpp", &cflags);

    // Extra include path
    cpp_binary.addIncludePath("./src/utils");

    // Link CPP
    cpp_binary.linkLibCpp();

    // Library path
    cpp_binary.addLibraryPath("./build");

    // Link related libs
    cpp_binary.linkSystemLibrary("a");
    cpp_binary.linkSystemLibrary("b");

    b.installArtifact(cpp_binary);

    const run_cmd = b.addRunArtifact(cpp_binary);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run-cpp", "Run C++ binary");
    run_step.dependOn(&run_cmd.step);

    // -----------------------------------------------------------------------
    // Zig binary
    // -----------------------------------------------------------------------
    const zig_binary = b.addExecutable(.{
        .name = "zig_binary",
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });

    b.installArtifact(zig_binary);

    const zig_run_cmd = b.addRunArtifact(zig_binary);
    zig_run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        zig_run_cmd.addArgs(args);
    }

    const zig_run_step = b.step("run-zig", "Run zig binary");
    zig_run_step.dependOn(&zig_run_cmd.step);
}
