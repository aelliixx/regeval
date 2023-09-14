# regeval
A compile time evaluated regular expression engine (WIP)


Only a small subset of the standard-compliant regular expressions are implemented

## Use
```cpp
int main()
{
  static constexpr const char* regexp = "Hello";
	static constexpr auto regex = alx::GenerateFsm<alx::Strlen(regexp)>(regexp);

  std::string to_test = "Hello, world!";
  assert(MatchString(regex, to_test));
}
```


## Building

```bash
mkdir build
cd build
cmake -G ninja ..
ninja && ./Regexp
```
