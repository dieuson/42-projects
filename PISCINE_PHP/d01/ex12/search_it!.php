#!/usr/bin/php
<?PHP
	function reject_empty_cell($tab, $cle)
	{
		$i = 0;
		$tab1 = array();
		foreach ($tab as $key)
		{
			if (!$key || strstr($key, "./search_it!.php")
			|| strstr($key, "search_it!.php") || !strcmp($key, $cle))
				unset($tab[$i]);
			else
			{
				$tab1[$i] = $key;
				$i++;
			}
		}
		return $tab1;
	}
	function verif_cle_val($str)
	{
		$tmp = explode($str, ':');
		$i = count($tmp);
		print("i =$i\n");
		print_r($tmp);
		if (count($tmp) != 2)
			return 0;
		print("ok\n");
		return 1;
	}

	function split_tab($argv_n)
	{
		$tab = explode($argv_n, ':');
		$tab = reject_empty_cell($tab, "");
		$str = implode(' ', $tab);
		$tab = explode($str, ' ');
		$tab = reject_empty_cell($tab, "");
	}

	if ($argc < 2)
			exit();
	else if (strchr($argv[1], ':'))
		exit("Error: No Key\n");
	$cle = $argv[1];
	$tab = reject_empty_cell($argv, $cle);
	foreach ($tab as $key)
	{
		if (verif_cle_val($key))
		{
			print("test\n");
			$splited_tab = split_tab($key);
		}	
	}
?>