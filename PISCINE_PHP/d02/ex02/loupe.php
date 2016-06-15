#!/usr/bin/php
<?PHP
	if ($argc > 1)
		exit ();
	while ($line = fgets(STDIN))
	{
/*		$regex = preg_replace('@(<a[^>]*?>).*?(<)@si', "$1ALLO$2", $line);
		$regex = preg_replace('#(title=")(.*)"#', '$1TITLE"', $regex);*/
		$regex = preg_replace_callback('@<a[^>]*?>(.*?)<@si', 
		function ($matches) 
		{
//			print_r($matches);
			$to_up = preg_replace('/$matches[1]/', strtoupper($matches[1]), $matches[0]);
//			print("to_up =$to_up\n");
			return  $to_up;
		}, $line);
//		$regex = preg_replace_callback(
//		"'s/a\(.*\)a/{\1}/g'",
//		function ($matches) {
//			return strtoupper($matches[0]);
//		}, $line);
		echo "$regex\n";
	}
?>