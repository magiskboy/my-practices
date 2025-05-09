

/*
 * Return a count of the total number of objects 'o' satisfying o.x == o.y.
 * 
 * Parameter(s):
 * objects: an array of objects with integer properties 'x' and 'y'
 */
function getCount(objects) {
    let c = 0;
    for (let o of objects) 
        if (o.x == o.y) ++c;
    return c;
}

