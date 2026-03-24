-- GENERATE SQUARE LIST COMPHRENSION
hundred_square :: [Int] -> Int
hundred_square xs = sum [(x^2)|x <-xs]

-- GRID
grid:: Int ->  Int -> [(Int,Int)]
grid x y = [(x,y)|x <-[0..x] , y <-[0..y]]

listSquare :: Int -> [Int] -> [Int]
listSquare n xs = foldr (\x acc -> (x * n):acc) [] xs

---SECOND GENERIC
--findGeneric:: Eq a => a ->[(a,b)] -> [b]
--findGeneric x tp = [v|(k,v) <- tp, k == x]
--FIND CHECK EQUALITY
find:: Char ->[(Char,Int)] -> [Int]
find x tp = [v|(k,v) <- tp, k == x]




