multiple :: [Int] -> [Int]
multiple xs = filter (\x ->x  `mod` 6 == 0)xs

threeChar :: [String] -> [String]
threeChar xs = filter (\x-> length x > 3)xs

removeEvenSquere :: [Double] -> [Double]
removeEvenSquere xs = [odd x^2|x <- even xs ]