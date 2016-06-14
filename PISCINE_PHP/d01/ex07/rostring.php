#!/usr/bin/php
<?php
	$tab = array();
	$i = 0;
	$j = 0;
	$tmp = explode(" ", $argv[1]);

	foreach ($tmp as $key) 
	{
		if ($key)
		{
			$tab[$j] = $tmp[$i];
			$j++;
		}
		$i++;
	}
	$i = 1;
	$last = $tab[0];
	while ($tab[$i])
	{
		echo "$tab[$i] ";
		$i++;
	}
	echo "$last\n";
?>