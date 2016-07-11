<?php
	function ft_is_sort($tab)
	{
		$i = 0;
		$j = 1;
		if (!is_array($tab))
			return false;
		while ($tab[$i])
		{
			if ($tab[$j])
			{
				if (strcmp($tab[$i], $tab[$j]) > 0)
					return false;
			}
			$i++;
			$j++;
		}
		return true;
	}
?>