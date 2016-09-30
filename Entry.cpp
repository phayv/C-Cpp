#include <iostream>

using namespace std;

class Greeting{
	public:
		Greeting(string x){
			setName(x);
		}
		void setName(string y){
			name = y;
		}
		void greet(){
			cout << name;
		};
	protected:

	private:
		string name;
};

int main(){

	Greeting HelloWorld("Hello World!\n");
	HelloWorld.greet();
	return 0;

}

