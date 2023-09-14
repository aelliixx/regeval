#include <Colours.hpp>
#include <Println.hpp>
#include <stacktrace>
#include <string>

struct testStruct {
    int x;
    int y;

    operator std::string() const
    {
        return "{" + std::to_string(x) + ", " + std::to_string(y) + "}";
    }
};

int main()
{

    alx::println("Hello, world");
    alx::println("Hello, {}", "world");
    alx::println("Hello, world {}", 2);
    alx::println("Hello, {}", false);

    alx::println();
    alx::println("-----------------------------");
    alx::println();

    alx::println(alx::Colour(), "This text is red");
    alx::println(alx::Colour::Green, "This text is green");
    alx::println(alx::Colour::Blue, "This text is dark blue");
    alx::println(alx::Colour::Pink, "This text is pink-ish");

    alx::println();
    alx::println("-----------------------------");
    alx::println();

    alx::println("Hey {;240}", "world");
    alx::println("Hey {;20;190;100}", "world");
    alx::println("Hey {;170;250;30}", "world");
    alx::println("Hey {;255;50;250}", "world");
    alx::println("Hey {;0;50;255}", "world");

    alx::println();
    alx::println("-----------------------------");
    alx::println();

    const testStruct foo = { 3, 10 };
    alx::println("{}", foo);
    alx::println("{v}", foo);
    alx::println("{v}", "{130, 44}");
    alx::println("{v}", "{10, 330, 231}");
    alx::println("{v}", "{3, 132, 32, 3214}");
    alx::println("{v}", "{3, 132, 32, 3214, 543}");

    alx::println();
    alx::println("-----------------------------");
    alx::println();

	alx::print("1.235 ");
	alx::print(alx::Colour(250, 200, 0), "[{}: {}({}:{})]", __FILE__, __FUNCTION__, __LINE__, __LINE__);
	alx::println(": hello from the source code");

    alx::println();
    alx::println("-----------------------------");
    alx::println();

	alx::println(alx::Colour::Orange, "{}", alx::Colour::Orange.to_string());
}
