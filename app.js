// Init pharse
var imageUrls = [
  './images/1.jpeg',
  './images/2.jpeg',
  './images/3.jpeg',
  './images/4.jpeg',
  './images/5.jpeg',
];
var imageFavoriteUrls = [];
var isShowMore = true;
var headImage = 0;
updateListImagesView(imageUrls);


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

function addFavoriteImage(url) {
  if (!imageFavoriteUrls.includes(url)) {
    imageFavoriteUrls.push(url);
    updateFavoriteImagesView(imageFavoriteUrls);
  }
}

function showImageView(target) {
  let imageUrl = target.getAttribute('src');
  let options = 'width=650,height=450,resizable=yes,scrollbars=yes,toolbar=yes,menubar=no,location=no,directories=no, status=yes';
  let imageWindow = open('view.html', 'Image view', options);

  imageWindow.onload = function() {
    imageWindow.document.getElementById('image').setAttribute('src', imageUrl);
    imageWindow.addFavoriteImage = function() {
      addFavoriteImage(imageUrl);
    }
  }
  imageWindow.focus();
}

function onDeleteFavoriteImage(event) {
  imageFavoriteUrls = imageFavoriteUrls.filter(function(imageUrl) {
    return imageUrl !== event.target.getAttribute("imageUrl");
  });
  let imageWrapperNode = event.target.parentNode;
  let favoriteImagesNode = imageWrapperNode.parentNode;
  favoriteImagesNode.removeChild(imageWrapperNode);
}

function makeImageFavoriteNode(imageUrl) {
  let imageWrapperNode = document.createElement("div");
  imageWrapperNode.classList.add('image-wrapper');
  let imageNode = document.createElement("img");
  imageNode.setAttribute('src', imageUrl);
  let deleteButtonNode = document.createElement("div");
  deleteButtonNode.classList.add('delete-btn');
  deleteButtonNode.textContent = 'Delete';
  deleteButtonNode.setAttribute("imageUrl", imageUrl);
  deleteButtonNode.addEventListener("click", onDeleteFavoriteImage);
  imageWrapperNode.appendChild(imageNode);
  imageWrapperNode.appendChild(deleteButtonNode);
  return imageWrapperNode;
}

function updateFavoriteImagesView(urls) {
  let favoriteImages = document.getElementById("photo-favorite").getElementsByClassName('container')[0];
  let child = favoriteImages.lastElementChild;
  while (child) {
    favoriteImages.removeChild(child);
    child = favoriteImages.lastElementChild;
  }

  for (let i = 0; i < urls.length; ++i) {
    imageNode = makeImageFavoriteNode(urls[i]);
    favoriteImages.appendChild(imageNode);
  }
}

function updateListImagesView(showImages) {
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
  updateListImagesView(showImages);
}

function onRightNavClick() {
  let showImages = rightRotateImageList(imageUrls);
  updateListImagesView(showImages);
}

function onShowMoreClick() {
  isShowMore = !isShowMore;
  updateListImagesView()
}
