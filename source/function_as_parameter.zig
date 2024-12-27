const std = @import("std");

fn foo(str: []const u8) void {
    std.debug.print("{s}\n", .{str});
}

fn asBody(comptime print: fn (str: []const u8) void) void {
    print("hello from function body");
}

fn asPointer(print: *const fn (str: []const u8) void) void {
    print("hello from function pointer");
}

pub fn main() void {
    asBody(foo);
    asPointer(foo);
}
