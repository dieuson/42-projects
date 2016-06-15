#!/usr/bin/php
<?PHP
	function ft_split($str)
	{
		$i = 0;
		$tab = explode(' ', $str);
		$tab1 = array();
		foreach ($tab as $key)
		{
			if ($key)
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
?>