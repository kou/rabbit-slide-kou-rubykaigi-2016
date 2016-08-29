require "gi"

module Hello
end

loader = GI::Loader.new(Hello)
loader.load("Hello")
