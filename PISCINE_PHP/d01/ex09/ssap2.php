#!/usr/bin/php
<?PHP
	function ft_split($str)
	{
		$i = 0;
		$tab = explode(' ', $str);
		$tab1 = array();
		foreach ($tab as $key)
		{
			if (!$key)
				unset($tab[$i]);
			else
			{
				$tab1[$i] = $key;
				$i++;
			}
		}	
		$tab = $tab1;
		$i = 0;
		while($tab[$i]) 
		{
			if ($tab[$i + 1] && strcmp(strtoupper($tab[$i]), strtoupper($tab[$i + 1])) > 0)
			{
				$tmp = $tab[$i + 1];
				$tab[$i + 1] = $tab[$i];
				$tab[$i] = $tmp;
				$i = 0;
			}
			else
		    	$i++;
		}
		return $tab;
	}

	function reject_prog_name($argv)
	{
		$tab = array();
		$i = 0;

		foreach ($argv as $key) 
		{
			if ($key && strcmp($key, "ssap2.php") && strcmp($key, "./ssap2.php"))
			{
				$tab[$i] = $key;
				$i++;
			}
		}
		return $tab;
	}

	function display_in_order($tab)
	{
		$i = 0;
		$tmp = array();
		foreach ($tab as $key)
		{
			if (ctype_alpha($key))
				print("$key\n");
			else
			{
				$tmp[$i] = $key;
				$i++;
			}
		}
		$tab = array();
		$i = 0;
		foreach ($tmp as $key)
		{
			if (ctype_alnum($key))
				print("$key\n");
			else
			{
				$tab[$i] = $key;
				$i++;
			}
		}
		$tmp = implode($tab, ' ');
		$tab = ft_split($tmp);
		foreach ($tab as $key)
			print("$key\n");
	}
	$str_join = implode($argv, ' ');
	$tab = ft_split($str_join);
	$tab = reject_prog_name($tab);
	display_in_order($tab);
?>