local function bubbleSort(elems)
    for i = 1, #elems do
        local swapped = false
        for j = 1, #elems - 1 do
            elems[j] = tonumber(elems[j])
            elems[j+1] = tonumber(elems[j+1])
            if elems[j] > elems[j+1] then
                swapped = true
                elems[j], elems[j+1] = elems[j+1], elems[j]
            end

            --print("i: "..i.." j: "..j)
        end
        if not swapped then
            break
        end
    end
    return elems
end

local function main()
    local output = false
    local file
    if #arg == 1 then
        file = 'reversed.csv'
    else
        file = arg[2]
    end
    local f = io.open('../.numbers/' .. file, 'r')
    local content = f:read('*all')
    f:close()
    local f = {}
    for line in content:gmatch("[^\n]+") do
        table.insert(f, line)
    end

    local startTime = os.clock()
    local result = bubbleSort(f)
    local endTime = os.clock()

    if output then
        for _, v in pairs(result) do
            io.write(v .. ', ')
        end
    end

    print('\n\nexecution time (ns):' .. (endTime-startTime)*1000000000) --convert to ns
end

main()