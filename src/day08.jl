let

   lines = readlines("../inputs/day08")
   tree_array = Array{Int, 2}(undef, length(lines), length(lines[1]))
   for i in 1:length(lines)
       for j in 1:length(lines[1])
           tree_array[i,j] = parse(Int, lines[i][j])
       end
    end    
    
   N = size(tree_array)[1]
   hidden = Array{Bool, 2}(undef, N-2, N-2)
  
   # the horribly wasteful way of doing it
   for i = 2:N-2
       for j = 2:N-2
           hidden[i-1, j-1] = false
           tree_height = tree_array[i,j]
            
           # check column wrong needs work
           for k = 1:N
               if tree_array[k,j] > tree_height
                   hidden[i-1,j-1] = true
                   break
               end
            end
           # check row wrong needs work
           for k = 1:N
               if tree_array[i,k] > tree_height
                   hidden[i-1,j-1] = true
               end 
           end
       end
    end
    
    
    display(hidden)

    nothing
end
