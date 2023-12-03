$corlibfiles = [System.Collections.Generic.List[string]]::new()

foreach ($item in Get-ChildItem ../Lib/System.Runtime -File -Recurse)
{
	if ($item.FullName.EndsWith(".cpp")) { $corlibfiles.Add($item.FullName) }
}

$extlibfiles = [System.Collections.Generic.List[string]]::new()

foreach ($item in Get-ChildItem ../Lib/System.Linq -File -Recurse)
{
	if ($item.FullName.EndsWith(".cpp")) { $extlibfiles.Add($item.FullName) }
}

if ($args[1] -eq "dll")
{
	Write-Output "Compiling Assembly System.Runtime"

	g++ $corlibfiles -c # -fpermissive

	g++ -o System.Runtime.dll *.o -shared

	Remove-Item *.o

	Copy-Item System.Runtime.dll ../Lib/Assembled/System.Runtime.dll

	Write-Output "Compiling Assembly System.Linq"

	g++ $extlibfiles -c # -fpermissive

	g++ -o System.Linq.dll *.o System.Runtime.dll -shared

	Remove-Item *.o

	Copy-Item System.Linq.dll ../Lib/Assembled/System.Linq.dll

	Write-Output "Compiling Assembly $($args[0])"

	g++ "$($args[0]).cpp" -c # -fpermissive

	g++ -o "$($args[0]).dll" "$($args[0]).o" System.Runtime.dll System.Linq.dll -shared # -fpermissive

	Write-Output "Generating Executable"

	g++ -o "$($args[0]).exe" "$($args[0]).Exe.cpp" "$($args[0]).dll" System.Runtime.dll

	Remove-Item *.o
}
else
{
	g++ -o "standalone/$($args[0]).exe" "$($args[0]).cpp" $corlibfiles $extlibfiles # -fpermissive
}
