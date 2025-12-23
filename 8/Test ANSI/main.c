#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	int i,r,g,b;
	char a;
	printf("A : ");
	while(a!=27){
	fflush(stdin);
	a = getch();
	switch(a){
			case 127:
				printf("\033[2K");
				break;
			case 72:
				printf("\033[1A");
				break;
			case 80:
				printf("\033[1B");
				break;
			case 13:
				printf("\n");
				break;
		case 'b':
			if(b<255)
			b+=5;
			break;
		case 'g':
			if(g<255)
			g+=5;
			break;
		case 'r':
			if(r<255)
			r+=5;
			break;
		case 'e':
			if(r>0)
			r-=5;
			break;
		case 'f':
			if(g>0)
			g-=5;
			break;
		case 'v':
			if(b>0)
			b-=5;
			break;
		default:
//			printf("\n%u\n", a);
			break;
	}
			if(r<0)r=0;
			if(g<0)g=0;
			if(b<0)b=0;
			if(a=='r'||a=='g'||a=='b'||a=='v'||a=='f'||a=='e')
			printf("\r\033[38;2;%d;%d;%dm[%3d ; %3d ; %3d]",r, g, b,r,g,b);
			fflush(stdout);
	}
	return 0;
}
