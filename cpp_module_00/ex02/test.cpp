#include <iostream>
#include <vector>

class acc {

	// acc();
	// ~acc();

	public:
		int	x;
		typedef acc t;
		acc() {std::cout<<"create"<<std::endl;};
		acc(int a) {
			this->x = a;
			std::cout << a << std::endl;
		};
		~acc() { std::cout<<"delete"<<std::endl;};
};
int main(void)
{

	int asdf[] = {1, 2, 3, 4};
	std::vector<acc::t> accs(asdf, asdf + 4);
	std::cout << accs[2].x;
}
