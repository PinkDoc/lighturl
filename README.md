## Lighturl
#### Features
* A streaming-parsing url parser
* Url string writer
### Usage

```
url hu, fu;
std::string http = "http://localhost:8080/index.html#p3";
std::string ftp = "ftp://pink:1234567@localhost:2000/lover.mp3";
hu.parse(http);
fu.parse(ftp);

assert(hu.host_ref() == "localhost");
assert(hu.port_ref() == 8080);
assert(fu.account_ref() == "pink");

auto cp_fu(fu);			// copy
auto mv_hu(std::move(hu));	// move

// For networking
std::string buffer = "http:/";
url u;
auto len = buffer.size();
for (auto i = 0; i < buffer.size(); ++i)
{
    u.parse(buffer[i]);
}

// buffer recv more data
buffer += "/192.168.1.1/index.htm";
for (auto i = len; i < buffer.size(); ++i)
{
    u.parse(buffer[i]);
}

std::cout << u.print() << std::endl;


```
