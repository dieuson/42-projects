#!/usr/bin/php
<?PHP
	function get_nums($argv)
	{
		if (strchr($argv[1], '+'))
			$tab = explode('+', $argv[1]);
		if (strchr($argv[1], '-'))
			$tab = explode('-', $argv[1]);
		if (strchr($argv[1], '*'))
			$tab = explode('*', $argv[1]);
		if (strchr($argv[1], '/'))
			$tab = explode('/', $argv[1]);
		if (strchr($argv[1], '%'))
			$tab = explode('%', $argv[1]);
		return $tab;
	}

	function get_sign($argv)
	{
		if (strchr($argv[1], '+'))
			return '+';
		if (strchr($argv[1], '-'))
			return '-';
		if (strchr($argv[1], '*'))
			return '*';
		if (strchr($argv[1], '/'))
			return '/';
		if (strchr($argv[1], '%'))
			return '%';
	}

	function calcul($tab, $sign)
	{
		if ($sign == '+')
			$result = $tab[0] + $tab[1];
		if ($sign == '-')
			$result = $tab[0] - $tab[1];
		if ($sign == '*')
			$result = $tab[0] * $tab[1];
		if ($sign == '/')
			$result = $tab[0] / $tab[1];
		if ($sign == '%')
			$result = $tab[0] % $tab[1];
		return $result;
	}

	function detect_letters($str)
	{
		$i = 0;
		$alphabet = " +-*/%0123456789";
		while ($str[$i])
		{
			if (!strchr($alphabet, $str[$i]))
				return 0;
			$i++;
		}
		return 1;
	}
	if ($argc != 2)
		exit("Incorrect Parameters\n");
	else if (!detect_letters($argv[1]))
		exit("Syntax Error\n");
	$tab = get_nums($argv);
	$sign = get_sign($argv);
	if ($sign && $tab)
		$result = calcul($tab, $sign);
	print("$result\n");
?>