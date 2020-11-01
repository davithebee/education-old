<?php
function add($x,$y){
  return $x + $y;
}
// Funkcja add - dodaje dwie wartości przywołane z głównego pliku.
function substract($x,$y){
  return $x - $y;
}
// Funkcja substract - dodaje dwie wartości przywołane z głównego pliku.
function multiply($x,$y){
  return $x * $y;
}
// Funkcja multiply - dodaje dwie wartości przywołane z głównego pliku.
function divide($x,$y){
  if($y==0) return 'ERROR';
  return $x / $y;
}
// Funkcja divide - dodaje dwie wartości przywołane z głównego pliku.
?>

<!-- Definicja Funkcji - Funkcja to zbiór instrukcji,
który posiada nazwę, zbiór argumentów (ale nie musi posiadać argumentów)
i znajduje się pomiędzy nawiasami {}.
Pozwala na wyodrębnienie fragmentu kodu programu w celu uniknięcia powtórzeń
i może być wielokrotnie wywoływana w kodzie.-->
