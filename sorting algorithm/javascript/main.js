const fs = require('fs')



function bubblesort(elems) {
    for (i = 0; i<elems.length; i++) {
        swapped = false

        for (j = 0; j<elems.length-1; j++) {
            if (elems[j] > elems[j+1]) {
                swapped = true
                temp = elems[j]
                elems[j] = elems[j+1]
                elems[j+1] = temp
            }

            //console.log(`i: ${i} j: ${j}`)
        }

        if (!swapped) break
    }

    return elems
}



function main() {
    print = false
    if (process.argv.length <= 2) {
        file = 'reversed.csv'
    } else {
        file = process.argv[2]
    }
    
    data = fs.readFileSync(`../.numbers/${file}`, 'utf-8').split('\r\n')

    for (i = 0; i<data.length; i++) data[i] = parseInt(data[i])

    startTime = process.hrtime.bigint()
    result = bubblesort(data).toString()
    endTime = process.hrtime.bigint()

    if (print) console.log(result)
    
    console.log(`\nexecution time (ns): ${endTime - startTime}`)
}



main()