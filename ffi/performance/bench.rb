require "benchmark"

require "ffi"
require "fiddle/import"

module FFICalc
  extend FFI::Library
  ffi_lib "calc"

  attach_function :calc_add, [:int, :int], :int
end

module FiddleCalc
  extend Fiddle::Importer
  dlload "libcalc.so"

  extern "int calc_add(int x, int y)"
end

def add(x, y)
  x + y
end

Benchmark.bmbm do |benchmark|
  n = 10_000_000

  benchmark.report("ffi") do
    n.times do
      FFICalc.calc_add(1, 2)
    end
  end

  benchmark.report("Fiddle") do
    n.times do
      FFICalc.calc_add(1, 2)
    end
  end

  benchmark.report("Method") do
    n.times do
      add(1, 2)
    end
  end

  benchmark.report("Direct") do
    n.times do
      1 + 2
    end
  end
end
