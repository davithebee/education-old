-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 15 Paź 2020, 15:51
-- Wersja serwera: 10.1.36-MariaDB
-- Wersja PHP: 7.2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `powtorzenie`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `leki`
--

CREATE TABLE `leki` (
  `IDLeku` int(10) UNSIGNED NOT NULL,
  `Producent` varchar(25) DEFAULT NULL,
  `Nazwa Miedzynarodowa` varchar(30) DEFAULT NULL,
  `Nazwa Preparatu` varchar(20) DEFAULT NULL,
  `Refundacja` tinyint(3) UNSIGNED DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Zrzut danych tabeli `leki`
--

INSERT INTO `leki` (`IDLeku`, `Producent`, `Nazwa Miedzynarodowa`, `Nazwa Preparatu`, `Refundacja`) VALUES
(10, NULL, NULL, NULL, 0),
(40, 'Kaguya Shinomiya', 'Kaguya-sama: Love is War', 'Kaguya-sama wa Kokur', 0),
(41, 'Okabe Rintarou', 'Steins;Gate', 'Steins;Gate', 20),
(42, 'Izuku Midoriya', 'My Hero Academia', 'Boku no Hero Academi', 30),
(43, 'Yuuko Aioi', 'My Ordinary Life', 'Nichijou', 40),
(44, 'Korosensei', 'Assasination Classroom', 'Ansatsu Kyoushitsu', 50),
(45, 'Shigeo Kageyama', 'Mob Psycho 100', 'Mob Psycho 100', 60),
(46, 'Kaede Akamatsu', 'Danganronpa V3', 'NEW Danganronpa V3', 70),
(47, 'Phoenix Wright', 'Ace Attorney', 'Gyakuten Kenji', 80),
(48, 'Megumin', 'Konosuba', 'Konosuba', 90),
(49, 'Saitama', 'One Punch Man', 'One Punch Man', 100);

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `leki`
--
ALTER TABLE `leki`
  ADD PRIMARY KEY (`IDLeku`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `leki`
--
ALTER TABLE `leki`
  MODIFY `IDLeku` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
