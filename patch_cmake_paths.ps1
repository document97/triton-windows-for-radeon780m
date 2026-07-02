
$oldPath = "C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9"
$newPath = $PSScriptRoot -replace '\\', '/'

if ($oldPath -eq $newPath) {
    Write-Host "Paths match, no patching needed."
    exit 0
}

$cmakeFiles = Get-ChildItem -Path "$PSScriptRoot\build\lib\cmake" -Recurse -Filter *.cmake
$count = 0
foreach ($file in $cmakeFiles) {
    $content = Get-Content -Path $file.FullName -Raw
    if ($content -match [regex]::Escape($oldPath)) {
        $content = $content -replace [regex]::Escape($oldPath), $newPath
        Set-Content -Path $file.FullName -Value $content -NoNewline
        $count++
    }
}
Write-Host "Patched $count cmake file(s). Old path -> $newPath"

