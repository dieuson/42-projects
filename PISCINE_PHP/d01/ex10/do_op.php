#!/usr/bin/php
<?PHP

	function reject_empty_cell($tab)
	{
		$i = 0;
		$tab1 = array();
		foreach ($tab as $key)
		{
			if (!$key || strstr($key, "./do_op.php") || strstr($key, "do_op.php"))
				unset($tab[$i]);
			else
			{
				$tab1[$i] = $key;
				$i++;
			}
		}
		return $tab1;
	}
	$str_join = implode($argv, ' ');
	$str_join2 = explode(' ', $str_join);
	$tab = reject_empty_cell($str_join2);
	if (count($tab) != 3)
		exit("Incorrect Parameters\n");
	if ($tab[1] == '+')
		$result = $tab[0] + $tab[2];
	if ($tab[1] == '-')
		$result = $tab[0] - $tab[2];
	if ($tab[1] == '*')
		$result = $tab[0] * $tab[2];
	if ($tab[1] == '/')
		$result = $tab[0] / $tab[2];
	if ($tab[1] == '%')
		$result = $tab[0] % $tab[2];
	if ($result)
		print("$result\n");
?>