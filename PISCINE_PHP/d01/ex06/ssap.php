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
			if ($tab[$i + 1] && strcmp($tab[$i], $tab[$i + 1]) > 0)
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
			if ($key && strcmp($key, "ssap.php") && strcmp($key, "./ssap.php"))
			{
				$tab[$i] = $key;
				$i++;
			}
		}
		return $tab;
	}

	$str_join = implode($argv, ' ');
	$tab = ft_split($str_join);
	$tab = reject_prog_name($tab);
	foreach ($tab as $key) 
	{
		print("$key\n");
	}
?>