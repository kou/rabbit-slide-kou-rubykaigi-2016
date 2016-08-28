require "ffi"

module LibHello
  extend FFI::Library
  ffi_lib "../../libhello/lib/libhello.so"
  attach_function :hello_new, [], :pointer
  attach_function :hello_message, [:pointer], :string
  attach_function :hello_free, [:pointer], :void
end

class Hello
  def initialize
    @hello = FFI::AutoPointer.new(LibHello.hello_new,
                                  LibHello.method(:hello_free))
  end

  def message
    LibHello.hello_message(@hello)
  end
end
