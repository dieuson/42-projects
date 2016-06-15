#!/usr/bin/php
<?PHP
	if ($argc <= 1)
		exit ();
	$regex = "Cette phrase contient des  espaces et des tabulations";
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