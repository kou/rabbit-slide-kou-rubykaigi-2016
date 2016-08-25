require "benchmark"

require "calc"

def add(x, y)
  x + y
end

Benchmark.bmbm do |benchmark|
  n = 10_000_000

  benchmark.report("Extension") do
    n.times do
      Calc.add(1, 2)
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
