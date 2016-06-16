#!/usr/bin/php
<?PHP
if ($argc != 2)
	exit();
$line = file_get_contents($argv[1]);
$line = preg_replace_callback("/<a (.*?)<\/a>/is", function ($matched)
{
	$modified_sentence = $matched[0];
	$modified_sentence = preg_replace_callback("/title=\"(.*?)\"/is", function ($str) 
		{ return "title=\"".strtoupper($str[1])."\""; 
		}, $modified_sentence);
	$modified_sentence = preg_replace_callback("/>(.+?)</s", function ($str) 
		{ return strtoupper($str[0]); 
		}, $modified_sentence);
	return $modified_sentence;
}, $line);
echo $line;
?>