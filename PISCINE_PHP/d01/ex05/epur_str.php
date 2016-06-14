#!/usr/bin/php
<?php
	$i = 0;
	$j = 0;
	$tab = array();

	if ($argc != 2)
		exit(0);
	$tmp = explode(" ", $argv[1]);
	foreach($tmp as $key)
	{
		if ($key)
		{
			$tab[$j] = $tmp[$i];
			$j++;
		}
		$i++;
	}
	$i = 0;
	while ($tab[$i])
	{
		echo "$tab[$i]";
		$i++;
		if ($tab[$i])
			echo " ";
	}
	echo "\n";
?>