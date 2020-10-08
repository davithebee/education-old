<?php
  $text = <<< LABEL
    zsl - Zespół
    Szkół
    Łączności<br>
LABEL;

  echo $text;
  echo nl2br($text),'<hr>';

  $name = 'jaNUsZ';
// zamiana na małe litery
  // $name = strtolower($name); //janusz
  echo strtolower($name),'<br>'; //janusz

// zamiana na duże litery
  echo strtoupper($name),'<br>'; //JANUSZ

// zamiana pierwszej litery w zdaniu
  $text = 'janusz nowak Mieszka w poznaniu';
  echo ucfirst($text),'<br>'; //Janusz nowak Mieszka w poznaniu

// zamiana wszystkich pierwszych liter w zdaniu
  $text = 'janusz nowak Mieszka w poznaniu';
  echo ucwords($text),'<hr>'; //Janusz Nowak Mieszka W Poznaniu

// Lorem Ipsum
  $lorem = <<< LOREM
    Lorem ipsum dolor sit amet consectetur adipisicing elit. Reiciendis qui beatae unde, magnam at fuga magni delectus quo obcaecati animi mollitia modi veritatis quaerat expedita voluptas nulla, sint cum eum.Lorem ipsum dolor sit amet consectetur adipisicing elit. Reiciendis qui beatae unde, magnam at fuga magni delectus quo obcaecati animi mollitia modi veritatis quaerat expedita voluptas nulla, sint cum eum.<hr>
LOREM;

  echo $lorem;
  $col = wordwrap($lorem, 40, '<br>');
  echo $col;
  $col = wordwrap($lorem, 40, '<hr>');
  echo $col;

// czyszczenie zawartości bufora
  //ob_clean();

// czyszczenie białych znaków
  $name = 'Anna';
  $name1 = '  Anna ';

  echo 'Dłogość $name: ',strlen($name); //4
  echo '<br>Dłogość $name1: ',strlen($name1);//7

  echo strlen(ltrim($name1)); //5
  echo strlen(rtrim($name1)); //6
  echo strlen(trim($name1)); //4

  $name1 = trim($name1);
  echo strlen($name1); //4

  //ob_clean();

// przetwarzanie ciągów znaków

  $replace = str_replace('%imie%', 'Janusz', 'Mam na imię %imie%');
  echo $replace, '<hr>';

//przetwarzanie ciągu znaków (np zamiana polskich znaków)
  $login = 'źdźbło';
  $censure = array('ą','ę','ć','ó','ś','ż','ź','ł','ń');
  $replace = array('a','e','c','o','s','z','z','l','n');

  $correctLogin = str_replace($censure, $replace, $login);
  echo $login, '<br>';
  echo $correctLogin, '<hr>';

//przeszukiwanie
  $address = "Poznań, ul. Polna 4, tel. (61) 123 44 55";
  $search = strstr($address, 'tel');
  echo $search,'<br>'; //tel. (61) 123 44 55

  $search = stristr($address, 'Tel'); //stristr - nie zwraca uwagi na wielkość liter
  echo $search,'<br>'; //tel. (61) 123 44 55

  $search = strstr($address, 'tel', true);
  echo $search,'<hr>'; //wszystko oprócz tel. (61) 123 44 55

  $mail = strstr('zsl@gmail.com', '@');
  echo $mail,'<br>';
  $mail = strstr('zsl@gmail.com', 64);
  echo $mail,'<hr>';

//substr
  $name = 'anna';
  echo substr($name, 0),'<br>'; //anna
  echo substr($name, 3),'<br>'; //a
  echo substr($name, 1, 2),'<br>'; //nn
  $name = 'krystyna';
  echo substr($name, 3, 3),'<hr>'; //sty

//pobierz domenę z dowolnego adresu poczty elektronicznej
  echo substr(strstr('janusz@gmail.com', '@'), 1);
?>
