--
addNumberList :: Int -> [Int] -> Maybe[Int]
addNumberList _ [] = Nothing
addNumberList n xs = Just (map(\x-> x +n) xs)

