# URL parser for modern c++

### usage

```
std::string s = "https://www.google.com/index.html"
url u;
auto code = u.parse(s);	// Ok or Invalid

auto mv_u = std::move(u); // Move 
auto cp_u = u; // Copy

// For networking
// The buffer can't recv for once, string may be like this "http:/",
// Your code should like this:
for (int i = lastIndex; i < s.size() ; ++i)
	if (u.parse(s[i]) != Ok) 
	{
		handle_err(...);
	}



```
