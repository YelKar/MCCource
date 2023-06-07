class Controller {
    constructor(cvs) {
        this.canvas = cvs;
        this.ctx = this.canvas.getContext("2d");

        this.width = cvs.width;
        this.height = cvs.height;

        this.stick = {
            defX: this.width / 2,
            defY: this.height / 2,
            _x: this.width / 2,
            _y: this.height / 2,
            get x() {
                return this._x
            },
            set x(x) {
                this._x = x;
                this.onMove()
            },
            get y() {
                return this._y
            },
            set y(y) {
                this._y = y;
                this.onMove()
            },
            radius: 60,
            fillStyle: "#000",
            onMove: () => {
                this.onMove()
            },
            draw: () => {
                this.update()
                this.ctx.beginPath();
                this.ctx.fillStyle = this.stick.fillStyle;
                this.ctx.arc(
                    this.stick.x,
                    this.stick.y,
                    this.stick.radius,
                    0,
                    2*Math.PI,
                )
                this.ctx.fill()
                this.ctx.closePath()
                this.ctx.beginPath()
                this.ctx.fillStyle = "#aaa";
                this.ctx.arc(
                    this.stick.x,
                    this.stick.y,
                    this.stick.radius/2,
                    0,
                    2*Math.PI,
                )
                this.ctx.fill()
                this.ctx.closePath()
            }
        }

        this.mouse = {
            x: 0,
            y: 0,
            isDown: 0,
            isInside: 0,
        }
        this.activateListeners()
    }
    activateListeners() {
        this.canvas.addEventListener("touchstart", () => this.mouse.isDown = true)
        this.canvas.addEventListener("touchend", () => this.mouse.isDown = false)
        this.canvas.addEventListener("touchmove", ev => {
            let el = this.canvas.getBoundingClientRect();
            ev.preventDefault()
            this.mouse.x = ev.touches[0].clientX - el.x;
            this.mouse.y = ev.touches[0].clientY - el.y;
        })
        this.canvas.addEventListener("mousedown", ()=> this.mouse.isDown = true);
        this.canvas.addEventListener("mouseup", () => this.mouse.isDown = false);
        this.canvas.addEventListener("mousemove", ev => {
            this.mouse.x = ev.offsetX;
            this.mouse.y = ev.offsetY;
        })

        this.canvas.addEventListener("mouseenter", () => this.mouse.isInside = true);
        this.canvas.addEventListener("mouseleave", () => this.mouse.isInside = false);
        window.addEventListener("mouseup", () => this.mouse.isDown = false)
    }
    update() {
        if (this.mouse.isDown) {
            this.moveTo(this.mouse.x, this.mouse.y, 20)
        } else {
            this.moveTo(this.stick.defX, this.stick.defY, 20);
        }
        this.updateSize();
    }
    updateSize() {
        this.stick.defX = this.canvas.width / 2;
        this.stick.defY = this.canvas.height / 2;

        this.stick.radius = Math.min(this.canvas.width, this.canvas.height) / 3;
    }
    moveTo(x, y, div) {
        let deltaX = parseInt(this.stick.x - x);
        let deltaY = parseInt(this.stick.y - y);
        if (deltaX != 0) {
            this.stick.x -= deltaX / div
        }
        if (deltaY != 0) {
            this.stick.y -= deltaY / div;
        }
    }
    setDefault() {
        this.stick.x = this.stick.defX;
        this.stick.y = this.stick.defY;
    }
    draw() {
        if (this != undefined) {
            this.ctx.beginPath();
            this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
            this.ctx.fillStyle = "#ddd";
            this.ctx.rect(0, 0, this.canvas.width, this.canvas.height);
            this.ctx.fill()
            this.ctx.closePath()
            this.stick.draw()
        }
    }
    onMove() {

    }
}
