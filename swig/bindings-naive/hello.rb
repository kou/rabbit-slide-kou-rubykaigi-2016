require "hello.so"

class WrappedHello
  class << self
    def finalizer(hello)
      lambda do |id|
        Hello.hello_free(hello)
      end
    end
  end

  def initialize
    @hello = Hello.hello_new
    ObjectSpace.define_finalizer(self, self.class.finalizer(@hello))
  end

  def message
    Hello.hello_message(@hello)
  end
end
