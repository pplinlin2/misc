#define TOSTR(a) #a
#define CONCAT(a, b) a##_##b

int main()
{
	char *str = TOSTR(abc); // TOSTR(abc) -> "abc"
	int CONCAT(var, 1) = 3; // CONCAT(var, 1) -> var_1

	return 0;
}
