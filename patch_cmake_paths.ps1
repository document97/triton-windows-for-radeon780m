param(
    [string]$LlvmSourcePath = (Join-Path $PSScriptRoot "llvm-project"),
    [string]$BuildPath = (Join-Path $PSScriptRoot "build")
)

$ErrorActionPreference = "Stop"
$originalRoot = "C:/Users/Glimmer/Documents/llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9"
$llvmSource = (Resolve-Path -LiteralPath $LlvmSourcePath).Path -replace '\\', '/'
$build = (Resolve-Path -LiteralPath $BuildPath).Path -replace '\\', '/'
$cmakeRoot = Join-Path $BuildPath "lib\cmake"

if (-not (Test-Path -LiteralPath (Join-Path $LlvmSourcePath "llvm\include\llvm"))) {
    throw "LLVM source headers were not found under '$LlvmSourcePath'. Use llvm-project commit 71a977d0."
}
if (-not (Test-Path -LiteralPath $cmakeRoot)) {
    throw "Pre-built LLVM CMake files were not found under '$cmakeRoot'."
}

$replacements = [ordered]@{
    "$originalRoot/build" = $build
    $originalRoot = $llvmSource
}
$changedFiles = 0
$utf8NoBom = New-Object System.Text.UTF8Encoding($false)

Get-ChildItem -LiteralPath $cmakeRoot -Recurse -Filter *.cmake | ForEach-Object {
    $content = Get-Content -LiteralPath $_.FullName -Raw
    $updated = $content
    foreach ($oldPath in $replacements.Keys) {
        $updated = $updated.Replace($oldPath, $replacements[$oldPath])
    }
    if ($updated -cne $content) {
        [System.IO.File]::WriteAllText($_.FullName, $updated, $utf8NoBom)
        $changedFiles++
    }
}

Write-Host "Patched $changedFiles CMake file(s)."
Write-Host "LLVM source: $llvmSource"
Write-Host "LLVM build:  $build"
