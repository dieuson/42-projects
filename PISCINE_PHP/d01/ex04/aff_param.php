#!/usr/bin/php
<?PHP
	$i = 0;
	foreach ($argv as $key) 
	{
		if ($i && strcmp($key, "aff_param.php") && strcmp($key, "./aff_param.php"))
			echo "$key\n";
		$i++;
	}
?>