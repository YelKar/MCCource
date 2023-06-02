let canvasL = document.querySelector("canvas#left");
let canvasR = document.querySelector("canvas#right");


setInterval(() => {
    canvasL.width = canvasL.height = innerWidth / 2.01;
    canvasR.width = canvasR.height = innerWidth / 2.01;
}, 10)

// let mouse = {
//     x: 0,
//     y: 0,
//     isDown: 0,
//     isInside: 0,
// }
//
// let stick = {
//     defX: canvas.width / 2,
//     defY: canvas.height / 2,
//     x: 0,
//     y: 0,
//     radius: 60,
//     fillStyle: "#000",
//     update() {
//         if (mouse.isDown) {
//             this.moveTo(mouse.x, mouse.y, 2);
//         } else {
//             this.moveTo(this.defX, this.defY, 4);
//         }
//         this.onMove();
//     },
//     moveTo(x, y, div) {
//         let deltaX = this.x - x;
//         let deltaY = this.y - y;
//         if (deltaX != 0) {
//             this.x -= deltaX / div;
//         }
//         if (deltaY != 0) {
//             this.y -= deltaY / div;
//         }
//     },
//     setDefault() {
//         this.x = this.defX;
//         this.y = this.defY;
//     },
//     draw() {
//         this.update()
//         ctx.beginPath();
//         ctx.fillStyle = this.fillStyle;
//         ctx.arc(
//             this.x,
//             this.y,
//             this.radius,
//             0,
//             2*Math.PI,
//         )
//         ctx.fill()
//         ctx.closePath()
//         ctx.beginPath()
//         ctx.fillStyle = "#aaa";
//         ctx.arc(
//             this.x,
//             this.y,
//             this.radius/2,
//             0,
//             2*Math.PI,
//         )
//         ctx.fill()
//         ctx.closePath()
//     },
//     onMove() {
//         eel.set(0, (this.x - canvas.width / 2) * 2, (this.y - canvas.height / 2) * 2, )
//     }
// }
//
// canvas.addEventListener("mousedown", ()=> mouse.isDown = true);
// canvas.addEventListener("mouseup", () => mouse.isDown = false);
// canvas.addEventListener("mousemove", ev => {
//     mouse.x = ev.offsetX;
//     mouse.y = ev.offsetY;
// })
// canvas.addEventListener("mouseenter", () => mouse.isInside = true);
// canvas.addEventListener("mouseleave", () => mouse.isInside = false);
// window.addEventListener("mouseup", () => mouse.isDown = false)
//
// function draw() {
//     ctx.beginPath()
//     ctx.clearRect(0, 0, canvas.width, canvas.height);
//     ctx.fillStyle = "#ddd";
//     ctx.rect(0, 0, canvas.width, canvas.height);
//     ctx.fill()
//     ctx.closePath()
//     stick.draw()
//     requestAnimationFrame(draw);
// }
//
// stick.setDefault()
// draw()


let ctrlL = new Controller(canvasL)
ctrlL.stick.radius = ctrlL.canvas.width / 2;
let ctrlR = new Controller(canvasR)
ctrlR.stick.radius = ctrlR.canvas.width / 2;
ctrlL.onMove = () => {
    eel.left(ctrlL.stick.x - ctrlL.canvas.width / 2);
    // ctrlL.stick.y - ctrlL.canvas.height / 2
    // console.log(0, ctrlL.stick.x - ctrlL.canvas.width / 2, ctrlL.stick.y - ctrlL.canvas.height / 2)
}
ctrlR.onMove = () => {
    eel.right_x(ctrlR.stick.x - ctrlR.canvas.width / 2);
    eel.right_y(ctrlR.stick.y - ctrlR.canvas.width / 2);
    // ctrlL.stick.y - ctrlL.canvas.height / 2
    // console.log(0, ctrlL.stick.x - ctrlL.canvas.width / 2, ctrlL.stick.y - ctrlL.canvas.height / 2)
}
!function play () {
    ctrlL.draw()
    ctrlR.draw()
    requestAnimationFrame(play)
}()
