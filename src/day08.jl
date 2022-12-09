let

   lines = readlines("../inputs/day08")
   tree_array = Array{Int, 2}(undef, length(lines), length(lines[1]))
   for i in 1:length(lines)
       for j in 1:length(lines[1])
           tree_array[i,j] = parse(Int, lines[i][j])
       end
    end    
    
   # find visable trees!

   nothing

end
