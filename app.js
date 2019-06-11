// Init pharse
var imageUrls = [
  './images/1.jpeg',
  './images/2.jpeg',
  './images/3.jpeg',
  './images/4.jpeg',
  './images/5.jpeg',
];
var isShowMore = true;
var headImage = 0;

updateShowListImage(imageUrls);

function getSubImages(images, start, size) {
  if (start + size > images.length) {
    const bend = size - (images.length - start);
    return new Array(...images.slice(start), ...images.slice(0, bend));
  }
  else {
    return images.slice(start, start + size);
  }
}

function leftRotateImageList(images) {
  headImage = headImage == 0 ? imageUrls.length - 1 : headImage - 1;
  return getSubImages(images, headImage, 5);
}

function rightRotateImageList(images) {
  headImage = headImage == imageUrls.length - 1 ? 0 : headImage + 1;
  return getSubImages(images, headImage, 5);
}

function updateShowListImage(showImages) {
  if (showImages !== undefined) {
    let imagesDOM = document.getElementById("list-images").children;
    for (let i = 0; i < imagesDOM.length; ++i) {
      imagesDOM[i].children[0].setAttribute("src", showImages[i]);
    }
  }

  if (isShowMore) {
    document.getElementsByClassName("img-1")[0].style.display = "block";
    document.getElementsByClassName("img-5")[0].style.display = "block";
  } else {
    document.getElementsByClassName("img-1")[0].style.display = "none";
    document.getElementsByClassName("img-5")[0].style.display = "none";
  }
}

function onLeftNavClick() {
  let showImages = leftRotateImageList(imageUrls);
  updateShowListImage(showImages);
}

function onRightNavClick() {
  let showImages = rightRotateImageList(imageUrls);
  updateShowListImage(showImages);
}

function onShowMoreClick() {
  isShowMore = !isShowMore;
  updateShowListImage()
}
