

int	main(int argc, char **argv)
{
	std::vector	list;

	if (argc < 2) {
		std::cout << argv[0] << " need an list." << std::endl;
		return (1);
	}
	else if (argc > 2) {
		std::cout << argv[0] << " need an unique list." << std::endl;
		return (1);
	}
	parseList(&list, argv);
}
