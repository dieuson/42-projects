<?PHP
	$name = $_GET['name'];
	$val = $_GET['value'];
	echo "name =$name val=$val\n";
	if ($_GET['action'] == "set")
	{
		setcookie($_GET[$name], $val, time() + 3600);
		echo "set\n";
	}
?>