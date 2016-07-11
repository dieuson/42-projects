#!/usr/bin/php
<?PHP
	if ($argc <= 1)
		exit ();
	$regex = $argv[1];
	while (preg_match('/\t/',$regex) || preg_match('/  /',$regex))
	{
		$regex = preg_replace('/\t/', ' ', $regex);
		$regex = preg_replace('/  /', ' ', $regex);
	}
	while (preg_match('/\t$/',$regex))
		$regex = preg_replace('/\t$/', '', $regex);

	while (preg_match('/ $/',$regex))
		$regex = preg_replace('/ $/', '', $regex);

	while (preg_match('/^\t/',$regex))
		$regex = preg_replace('/^\t/', '', $regex);

	while (preg_match('/^ /',$regex))
		$regex = preg_replace('/^ /', '', $regex);
	print("$regex\n");
?>