

function getMaxLessThanK(n, k) {
    let ret = 0;
    for (let i = 1; i < n; ++i) {
        for (let j = i + 1; j <= n; ++j) {
            let v = i & j;
            if (ret < v && v < k) ret = v;
        }
    }
    return ret;
}

