-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 29, 2018 at 12:09 PM
-- Server version: 10.1.13-MariaDB
-- PHP Version: 5.6.20

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dsms`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `id` int(50) NOT NULL,
  `name` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `name`, `email`, `password`) VALUES
(1, 'Md Sazibur Rahman', 'srmd440@gmail.com', 'sazib123'),
(2, 's', 's', 's');

-- --------------------------------------------------------

--
-- Table structure for table `exam`
--

CREATE TABLE `exam` (
  `name` varchar(50) NOT NULL,
  `roll` int(50) NOT NULL,
  `rag` int(50) NOT NULL,
  `class` varchar(50) NOT NULL,
  `free` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `exam`
--

INSERT INTO `exam` (`name`, `roll`, `rag`, `class`, `free`) VALUES
('Md sazibur Rahman', 375687, 225414, '6th', 150),
('Md jabed', 1, 2, '10th', 400);

-- --------------------------------------------------------

--
-- Table structure for table `month`
--

CREATE TABLE `month` (
  `name` varchar(50) NOT NULL,
  `roll` int(50) NOT NULL,
  `rag` int(50) NOT NULL,
  `class` varchar(50) NOT NULL,
  `free` int(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `month`
--

INSERT INTO `month` (`name`, `roll`, `rag`, `class`, `free`) VALUES
('Md sazibur Rahman', 1, 10, '6th', 100),
('Md jasim', 2, 20, '7th', 200);

-- --------------------------------------------------------

--
-- Table structure for table `result`
--

CREATE TABLE `result` (
  `name` varchar(50) NOT NULL,
  `roll` int(50) NOT NULL,
  `rag` int(50) NOT NULL,
  `class` varchar(50) NOT NULL,
  `section` varchar(50) NOT NULL,
  `year` int(50) NOT NULL,
  `gpa` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `result`
--

INSERT INTO `result` (`name`, `roll`, `rag`, `class`, `section`, `year`, `gpa`) VALUES
('Md sazib', 1, 10, '6th', 'A', 2010, 3.14),
('Md Jasim Uddin', 2, 20, '7th', 'A', 2011, 5),
('Md Foyzol Islam', 3, 30, '8th', 'A', 2012, 3.95),
('Md kamal hossine', 4, 40, '9th', 'A', 2013, 4.26),
('Md Asif', 5, 50, '6th', 'A', 2014, 5);

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `name` varchar(50) NOT NULL,
  `fname` varchar(50) NOT NULL,
  `mname` varchar(50) NOT NULL,
  `age` int(50) NOT NULL,
  `gender` varchar(50) NOT NULL,
  `roll` int(50) NOT NULL,
  `rag` int(50) NOT NULL,
  `class` varchar(50) NOT NULL,
  `section` varchar(50) NOT NULL,
  `city` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`name`, `fname`, `mname`, `age`, `gender`, `roll`, `rag`, `class`, `section`, `city`) VALUES
('Md sazibur Rahman', 'Md bazlur Rahman', 'Robiya Begum', 19, 'Femail', 1, 10, '6th', 'B', 'Comilla'),
('Md jasim', 'Md Aziz', 'Amena Begum', 29, 'Male', 2, 20, '7th', 'A', 'Comilla'),
('Md Foyzul Islam', 'Md Bazlur Rahman', 'Robiya Begum', 21, 'Male', 3, 30, '8th', 'B', 'Comilla'),
('Md Kamrul Hasan', 'Fozlu Beparey', 'Habeza Begum', 22, 'Male', 4, 40, '9th', 'A', 'Comilla'),
('Md Asif Abdullah', 'Md Abush Shattar', 'Lepi Begum', 22, 'Male', 5, 50, '10th', 'A', 'Comilla');

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

CREATE TABLE `teacher` (
  `id` int(50) NOT NULL,
  `name` varchar(50) NOT NULL,
  `fname` varchar(50) NOT NULL,
  `mname` varchar(50) NOT NULL,
  `age` int(50) NOT NULL,
  `gender` varchar(50) NOT NULL,
  `subject` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL,
  `phone` varchar(50) NOT NULL,
  `city` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `teacher`
--

INSERT INTO `teacher` (`id`, `name`, `fname`, `mname`, `age`, `gender`, `subject`, `email`, `phone`, `city`) VALUES
(1, 'Md sazibur Rahman', 'Md Bazlur Rahman', 'Robiya Begoum', 19, 'Male', 'Math', 'srmd440@gmail.com', '01872567260', 'Comilla'),
(2, 'Md Jasim uddin', 'Md abdul Aziz', 'Amena Begun', 29, 'Male', 'English', 'jasim@gmail.com', '01850281887', 'comilla'),
(3, 'Md Foyzol Islam', 'Md Bazlur Rahman', 'Robiya Begum', 21, 'Male', 'Bangla', 'foyzol@gmail.com', '01850275292', 'Comilla'),
(5, 'Md kamrul Hasan', 'Fozlu Bepari', 'Habeza Begum', 22, 'Male', 'Others', 'kamrul@gmail.com', '01865890902', 'Comilla'),
(4, 'Md Asif Abdullah', 'Md Abdus Shattar', 'Lipe Begum', 22, 'Male', 'Others', 'asif@gmail.com', '01825417894', 'Comilla');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
