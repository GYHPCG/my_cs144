#include <stdexcept>

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  // Your code here.
  //(void)data;
  const size_t size = min(data.length(),capacity_ - buffer_.size());
  data = data.substr(0, size);

  for (const auto& ch: data) {
	  buffer_.push_back(ch);
  }

  written_size_ += size;
}

void Writer::close()
{
  // Your code here.
  is_closed_ = true;
}

void Writer::set_error()
{
  // Your code here.
  is_err_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return is_closed_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - buffer_.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return written_size_;
}

string_view Reader::peek() const
{
  // Your code here.
  return {std::string_view(&buffer_.front(), 1)};
}

bool Reader::is_finished() const
{
  // Your code here.
  return buffer_.empty() && is_closed_;
}

bool Reader::has_error() const
{
  // Your code here.
  return is_err_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  const size_t size = std::min(len, buffer_.size());
  buffer_.erase(buffer_.begin(), buffer_.begin() + (size));
  read_size_ += size;

}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return buffer_.size();
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return read_size_;
}
