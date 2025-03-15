#include <iostream>

using namespace std;

void move_block( int n, string s, string tmp, string f ){
	if ( n == 1 ){
		cout << "Move block " << n << " from " << s << " to " << f << endl;
	}
	else{
		move_block( n-1, s, f, tmp );
		move_block( 1, s, tmp, f );
		move_block( n-1, tmp, s, f );
	}
}

int main(){
	move_block( 10, "start", "temp", "end" );
	return 0;
}
