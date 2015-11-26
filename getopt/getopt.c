#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int cmd_opt = 0;
	while(1){
		cmd_opt = getopt(argc, argv, "ab:c::");

		if(cmd_opt == -1)
			break;

		if(cmd_opt != '?')
			printf("option: -%c\n", cmd_opt);

		switch(cmd_opt){
		/* No args */
		case 'a':
			break;

		/* Single arg */
		case 'b':
			printf("option arg: %s\n", optarg);
			break;

		/* Optional args */
		case 'c':
			if(optarg)
				printf("option arg: %s\n", optarg);
			break;
		}
	}

	if(argc > optind){
		int i;
		for(i = optind; i < argc; i++)
			printf("argv[%d] = %s\n", i, argv[i]);
	}

	return 0;
}
