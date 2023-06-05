const std = @import("std");
const print = std.debug.print;
const c = @cImport({
    @cInclude("a.h");
    @cInclude("b.h");
});

///
///
///
pub fn main() !void {
    print("\n>>> Calling C++ lib function in Zig:)\n", .{});

    const a_result = c.AResult_init(999, true);
    print("\n>>> a_result value: {d}", .{c.AResult_get_value(a_result)});
    print(
        "\n>>> a_result is_success: {s}\n",
        .{if (c.AResult_is_success(a_result)) "true" else "false"},
    );
    c.AResult_print(a_result);
    c.AResult_free(a_result);

    const b_result = c.BResult_init(55.456);
    print("\n>>> b_result value: {d:.3}", .{c.BResult_get_float_value(b_result)});
    c.BResult_print(b_result);
    c.BResult_free(b_result);
}
