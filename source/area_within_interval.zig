const std = @import("std");
const Print = std.debug.print;

const area_within_interval = struct {
    partition: f64 = undefined,
    summation: f64 = undefined,
    left: f64 = undefined,
    right: f64 = undefined,
    interval: c_int = undefined,

    pub fn calculateArea(self: area_within_interval, interval: u64, comptime func: func_area_under_curve_t) area_within_interval {
        const div: f64 = 1.0 / @as(f64, @floatFromInt(interval));
        const sub_interval: f64 = (self.right - self.left) * div;
        var temp: f64 = 0.0;
        var i: f64 = 0.0;

        while (i <= self.right) {
            const temp_2: f64 = func.partition_fn(i) * div;
            temp += temp_2;
            i += sub_interval;
        }
        return area_within_interval{ .partition = temp, .summation = func.summation_fn(div), .left = self.left, .right = self.right };
    }
};

const func_area_under_curve_t = struct {
    partition_fn: *const fn (x: f64) f64,
    summation_fn: *const fn (x: f64) f64,

    pub fn init(partition: *const fn (x: f64) f64, summation: *const fn (x: f64) f64) func_area_under_curve_t {
        return func_area_under_curve_t{ .partition_fn = partition, .summation_fn = summation };
    }
};

fn quadraticPartition(x: f64) f64 {
    return x * x;
}

fn quadraticSummation(x: f64) f64 {
    return ((1.0 + x) * (2.0 + x)) / 6.0;
}

pub fn main() u8 {
    const STEP: u64 = 1000;
    const MAX_N: u64 = 5000;

    const main_functions: func_area_under_curve_t = .{ .partition_fn = quadraticPartition, .summation_fn = quadraticSummation };
    var main_output = area_within_interval{ .left = 0.0, .right = 1.0 };
    var n: u64 = 1;
    while (n <= MAX_N + STEP) {
        main_output = main_output.calculateArea(n, main_functions);
        Print("k:{d} | partition = {d} | summation = {d}\n", .{ n, main_output.partition, main_output.summation });
        n += STEP;
    }
    return 0;
}
