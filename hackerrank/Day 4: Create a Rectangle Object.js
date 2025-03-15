

/*
 * Complete the Rectangle function
 */
function Rectangle(a, b) {
    this.width = b;
    this.length = a;
    let self = this;
    
    this.perimeter =  2 * (this.width + this.length);

    this.area = this.width * this.length;
}

